"""Independent BATMAN v2 overall + v3 stage score/QR validator. No network writes."""
import argparse,binascii,json,re
PREFIX='NGPC-DEV.COM/BATMAN/'
SALT='BATMAN63'
BUDGETS=[480,300,60,180,720]
def speed_bonus(stage,ticks):return max(0,BUDGETS[stage-1]-(ticks*20//1199))*100
def encode(initials,base,total,mask,splits):
    bonus=sum(speed_bonus(i+1,t)for i,t in enumerate(splits)if mask&(1<<i))
    score=min(999999,base+bonus)
    body='BATMAN2'+initials+f'{score:07d}{base:07d}{total:07d}{mask:02d}'+''.join(f'{v:07d}'for v in splits)
    return PREFIX+body+f'{binascii.crc_hqx((body+SALT).encode(),0xffff):04X}'
def encode_stage(initials,stage,points,ticks):
    if not re.fullmatch(r'[A-Z]{3}',initials) or stage not in range(1,6) or not 0<=points<=999999 or not 1<=ticks<=9999999:
        raise ValueError('stage inputs')
    score=min(999999,points+speed_bonus(stage,ticks))
    if not score:raise ValueError('zero points')
    body='BATMAN3'+initials+str(stage)+f'{score:07d}{points:07d}{ticks:07d}'
    return PREFIX+body+f'{binascii.crc_hqx((body+"BATMAN65").encode(),0xffff):04X}'
def decode_stage(text):
    if not text.startswith(PREFIX):raise ValueError('URL prefix')
    p=text[len(PREFIX):]
    if not re.fullmatch(r'BATMAN3[A-Z]{3}[1-5][0-9]{21}[0-9A-F]{4}',p):raise ValueError('stage payload shape')
    if p[32:]!=f'{binascii.crc_hqx((p[:32]+"BATMAN65").encode(),0xffff):04X}':raise ValueError('stage checksum')
    stage=int(p[10]);score=int(p[11:18]);points=int(p[18:25]);ticks=int(p[25:32]);bonus=speed_bonus(stage,ticks)
    if not 1<=ticks<=9999999 or not 0<=points<=999999 or not 1<=score<=999999 or score!=min(999999,points+bonus):raise ValueError('stage formula')
    return {'gameCode':'BATMAN','version':3,'initials':p[7:10],'stage':stage,'score':score,'sourcePoints':points,'speedBonus':bonus,'stageTicks':ticks}
def decode(text):
    if text.startswith(PREFIX+'BATMAN3'):return decode_stage(text)

    if not text.startswith(PREFIX):raise ValueError('URL prefix')
    p=text[len(PREFIX):]
    if not re.fullmatch(r'BATMAN2[A-Z]{3}[0-9]{58}[0-9A-F]{4}',p):raise ValueError('payload shape')
    if p[68:]!=f'{binascii.crc_hqx((p[:68]+SALT).encode(),0xffff):04X}':raise ValueError('checksum')
    score=int(p[10:17]);base=int(p[17:24]);total=int(p[24:31]);mask=int(p[31:33]);splits=[int(p[33+i*7:40+i*7])for i in range(5)]
    if not 0<=base<=999999 or not 1<=total<=9999999 or mask not in [0,1,3,7,15,31] or sum(splits)!=total:raise ValueError('bounds/mask/split sum')
    n=mask.bit_count()
    if any(splits[i]<1 for i in range(n))or any(splits[i]!=0 for i in range(n+1,5)):raise ValueError('completed/future stage times')
    bonus=sum(speed_bonus(i+1,t)for i,t in enumerate(splits)if mask&(1<<i))
    if not 1<=score<=999999 or score!=min(999999,base+bonus):raise ValueError('score formula')
    return {'gameCode':'BATMAN','version':2,'initials':p[7:10],'score':score,'sourcePoints':base,'speedBonus':bonus,'totalTicks':total,'completedMask':mask,'completedStages':n,'fullGameComplete':mask==31,'stageTicks':splits,'timeSecondsNumerator':total*20,'timeSecondsDenominator':1199}
def selftest():
    valid=[encode('AAA',2020,800,0,[800,0,0,0,0]),encode('BOB',3400,10200,1,[9000,1200,0,0,0]),encode('END',45000,32000,31,[9000,6000,2000,3000,12000]),encode('MAX',999999,9999999,0,[9999999,0,0,0,0])]
    for e in valid:
        decode(e)
        for bad in [e[:-1],e+'A',e[:-4]+'0000',e.replace('BATMAN2','BATMAN1',1)]:
            try:decode(bad)
            except ValueError:pass
            else:raise AssertionError('accepted malformed text')
    # Valid CRCs cannot make invalid zero scores, impossible stage progress,
    # zero completed-stage duration or inconsistent split totals acceptable.
    for base,total,mask,splits in [(0,50,0,[50,0,0,0,0]),(50,0,0,[0,0,0,0,0]),(50,50,2,[0,50,0,0,0]),(50,50,1,[0,50,0,0,0]),(50,50,0,[40,10,0,0,0]),(50,50,0,[30,0,0,0,0])]:
        try:decode(encode('BAD',base,total,mask,splits))
        except ValueError:pass
        else:raise AssertionError('accepted invalid record')
    # Waiting, then dying at zero earns nothing; clears alone earn a bonus,
    # and a faster equal clear earns more without any decreasing live score.
    assert speed_bonus(1,600)<speed_bonus(1,300)
    for stage in range(1,6):
        e=encode_stage('ABC',stage,2020,500+stage)
        assert decode(e)['score']==min(999999,2020+speed_bonus(stage,500+stage))
        for bad in (e[:-1],e+'Z',e[:-4]+'0000',e.replace('BATMAN3','BATMAN2',1)):
            try:decode(bad)
            except ValueError:pass
            else:raise AssertionError('accepted invalid stage QR')
    print('PASS',len(valid),'overall vectors and 5 stage formats; invalid QR vectors rejected')
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('text',nargs='?');ap.add_argument('--selftest',action='store_true');a=ap.parse_args()
    if a.selftest:selftest()
    elif a.text:print(json.dumps(decode(a.text),indent=2))
    else:ap.error('give QR text or --selftest')
