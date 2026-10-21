"""Original-game-art print layouts. Reader pages are exactly 81 x 110 mm."""
from pathlib import Path
from io import BytesIO
import json,shutil
from reportlab.pdfgen import canvas
from reportlab.lib.units import mm
from reportlab.lib import colors
from reportlab.lib.styles import ParagraphStyle
from reportlab.platypus import Paragraph
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from pypdf import PdfReader,PdfWriter,Transformation
from pypdf.generic import RectangleObject
P=Path(__file__).resolve().parent
C=P/'candidate' if (P/'candidate').is_dir() else Path(__file__).resolve().parents[2]
O=(P/'PRINT_KIT') if (P/'candidate').is_dir() else C/'PRINT_KIT'
T=(P/'tmp/pdfs') if (P/'candidate').is_dir() else C/'tmp/pdfs'
O.mkdir(exist_ok=True);T.mkdir(parents=True,exist_ok=True)
pdfmetrics.registerFont(TTFont('Body','/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf'))
pdfmetrics.registerFont(TTFont('Bold','/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf'))
pdfmetrics.registerFont(TTFont('Title','/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf'))
pdfmetrics.registerFont(TTFont('Mono','/usr/share/fonts/truetype/dejavu/DejaVuSansMono-Bold.ttf'))
GOLD=colors.HexColor('#BD8D35');INK=colors.HexColor('#101923');PAPER=colors.HexColor('#F4F0E7');DIM=colors.HexColor('#59636A');WHITE=colors.white
W,H=81*mm,110*mm;M=6*mm;CW=W-2*M;logo=C/'REFERENCE_ASSETS/258144.jpg';bounds=[]
shots={n:C/'REFERENCE_ASSETS/ENDING_SOURCES'/f'level{n}.png'for n in range(1,6)}
def txt(c,x,y,s,size=8,font='Body',color=INK):c.setFont(font,size);c.setFillColor(color);c.drawString(x,y,s)
def center(c,y,s,size=9,font='Bold',color=INK,w=W,x=0):c.setFont(font,size);c.setFillColor(color);c.drawCentredString(x+w/2,y,s)
def para(c,x,top,w,text,size=7.5,leading=10.4,color=INK):
 style=ParagraphStyle('p',fontName='Body',fontSize=size,leading=leading,textColor=color,spaceAfter=0)
 p=Paragraph(text,style);pw,ph=p.wrap(w,1000);p.drawOn(c,x,top-ph);bounds.append((c._pageNumber,top-ph));return top-ph
def brand(c,x,y,w,h):
 c.setFillColor(WHITE);c.rect(x,y,w,h,fill=1,stroke=0);size=w/16.0
 txt(c,x+3*mm,y+h*0.30,'NEO GEO POCKET',size,'Bold',INK)
 word='COLOR';size=w/24;start=x+w*0.72
 for i,(ch,col)in enumerate(zip(word,['#D44045','#D79A18','#42A45F','#277DB3','#9A4DA3'])):txt(c,start+i*size*.72,y+h*.32,ch,size,'Bold',colors.HexColor(col))
def footer(c,n):
 c.setStrokeColor(GOLD);c.setLineWidth(.55);c.line(M,7*mm,W-M,7*mm)
 txt(c,M,3.8*mm,'BATMAN / NEO GEO POCKET COLOR',4.8,'Bold',DIM);txt(c,W-10*mm,3.8*mm,f'{n:02}',6.5,'Bold',INK)
def page(c,n,kicker,title):
 c.setFillColor(PAPER);c.rect(0,0,W,H,fill=1,stroke=0)
 c.setFillColor(INK);c.rect(0,H-7*mm,W,7*mm,fill=1,stroke=0)
 txt(c,M,H-4.8*mm,kicker.upper(),5.7,'Bold',GOLD)
 txt(c,M,H-15.5*mm,title,13.2,'Title',INK);footer(c,n)
def screen(c,path,top,width=60*mm):
 height=width*152/160;x=(W-width)/2;c.setFillColor(INK);c.roundRect(x-mm,top-height-mm,width+2*mm,height+2*mm,1.5*mm,fill=1,stroke=0)
 c.drawImage(str(path),x,top-height,width,height,mask='auto');return top-height
def cover(c,x,y,w,h,manual=False):
 c.setFillColor(colors.black);c.rect(x,y,w,h,fill=1,stroke=0);brand(c,x,y+h-9*mm,w,9*mm)
 c.drawImage(str(logo),x+3*mm,y+h*.34,w-6*mm,(w-6*mm)*2/3,mask='auto')
 center(c,y+h*.235,'BATMAN',w*.155,'Title',GOLD,w,x);center(c,y+h*.17,'THE MOVIE',w*.038,'Bold',WHITE,w,x)
 c.setStrokeColor(GOLD);c.setLineWidth(.6);c.line(x+8*mm,y+h*.12,x+w-8*mm,y+h*.12)
 center(c,y+h*.075,'INSTRUCTION MANUAL'if manual else'PORTED BY JAJABINX35',w*.025,'Bold',WHITE,w,x)
 center(c,y+h*.033,'PORTED BY JAJABINX35'if manual else'UNOFFICIAL FAN PORT',w*.018,'Body',GOLD,w,x)
manual=O/'Batman_NGPC_Instruction_Manual_81x110mm.pdf';c=canvas.Canvas(str(manual),pagesize=(W,H));c.setTitle('Batman: The Movie - NGPC instruction manual');c.setAuthor('jajabinx35 - NGPC port')
cover(c,0,0,W,H,True);c.showPage()
page(c,2,'Gotham City','YOUR MISSION')
y=para(c,M,89*mm,CW,'Gotham is under threat. Take Batman from the danger of Axis Chemicals to the streets, skies and rooftops of the city. Drive the Batmobile, solve the Batcave mystery, pilot the Batwing and climb Gotham Cathedral to confront the Joker.')
txt(c,M,y-8*mm,'INSIDE THIS BOOKLET',8,'Bold',GOLD)
for i,(a,b)in enumerate([('Controls and getting started','03-04'),('Five stages of action','05-09'),('The screen and scoring','10-11'),('Saving, records and QR','12-14'),('Credits','15')]):
 yy=y-15*mm-i*8*mm;txt(c,M,yy,a,7.1);txt(c,W-17*mm,yy,b,7.1,'Bold')
c.showPage()
page(c,3,'Know your controls','THE DARK KNIGHT')
# A simple control diagram, not an invented gameplay illustration.
x,y,w,h=8*mm,55*mm,65*mm,34*mm;c.setFillColor(INK);c.roundRect(x,y,w,h,6*mm,fill=1,stroke=0)
c.setFillColor(colors.HexColor('#444C55'));c.roundRect(x+19*mm,y+4*mm,29*mm,25*mm,2*mm,fill=1,stroke=0)
c.setFillColor(colors.black);c.rect(x+22*mm,y+7*mm,23*mm,19*mm,fill=1,stroke=0)
c.setFillColor(GOLD);c.circle(x+9*mm,y+16*mm,5*mm,fill=1,stroke=0)
for xx,yy,label in [(57,22,'A'),(52,12,'B')]:
 c.setFillColor(GOLD);c.circle(x+xx*mm,y+yy*mm,3.1*mm,fill=1,stroke=0);txt(c,x+xx*mm-1.1*mm,y+yy*mm-1.1*mm,label,7,'Bold',INK)
c.setFillColor(GOLD);c.roundRect(x+53*mm,y+28*mm,7*mm,2*mm,1*mm,fill=1,stroke=0);txt(c,x+49*mm,y+31*mm,'OPTION',4.5,'Bold',WHITE)
for i,(a,b)in enumerate([('D-PAD','Move and climb'),('A','Throw a batarang'),('B','Use the grapple'),('DOWN + B','Downward / drop action'),('OPTION','Pause the game')]):
 yy=47*mm-i*6.4*mm;txt(c,M,yy,a,7.2,'Bold');txt(c,31*mm,yy,b,7.1)
para(c,M,15*mm,CW,'Platform controls apply to Axis Chemicals and Gotham Cathedral.',6.2,8.2,DIM);c.showPage()
page(c,4,'Main menu','GETTING STARTED')
menu=C/'DOCUMENTATION/BATMAN_Title_160x152.png';screen(c,menu,89*mm,45*mm)
y=para(c,M,42*mm,CW,'<b>NEW GAME</b> begins a fresh run. <b>CONTINUE</b> appears when a saved checkpoint is available. <b>OPTIONS</b> lets you change sound and starting lives. <b>RECORDS</b> holds your scores; <b>CREDITS</b> plays the full music and picture sequence.',7.3,10)
para(c,M,y-3*mm,CW,'Start with three lives or fewer to qualify for records. Use Up/Down to choose and A to select; B returns from a menu.',7.2,9.8);c.showPage()
stage_pages=[
 (1,5,'AXIS CHEMICALS','Stay alert among the factory platforms. Climb, jump and use the grapple to reach higher ground. Throw batarangs at threats ahead. Down+B performs the original downward/drop action.'),
 (2,6,'THE BATMOBILE','Steer with Left/Right. Up/Down controls acceleration and braking. Use A or B with Left/Right to grapple at the appropriate route markers. Watch the road signs and other traffic.'),
 (3,7,'THE BATCAVE','Identify the three products before time runs out. Use the D-pad to select and A or B to choose. You have seven guesses. Study the feedback from each attempt before trying again.'),
 (4,8,'THE BATWING','Fly and steer with the D-pad. A or B fires; combine a fire button with Up/Down for throttle control. Destroy the balloons while avoiding danger over Gotham.'),
 (5,9,'GOTHAM CATHEDRAL','Climb toward the final confrontation. Platform controls return: A throws batarangs, B grapples and Down+B performs the downward/drop action. Keep an eye on your health and the route above.')]
for n,p,title,body in stage_pages:
 page(c,p,f'Stage {n:02}',title);screen(c,shots[n],88*mm,60*mm);para(c,M,27*mm,CW,body,7.15,9.6);c.showPage()
page(c,10,'Read the action','THE GAME SCREEN')
screen(c,shots[1],88*mm,48*mm)
for i,(label,body)in enumerate([('HP','Your remaining health.'),('PTS','Points earned in the current run.'),('BEST','Your highest recorded score.'),('TIME','The stage countdown.'),('LIFE','Lives remaining, including this life.')]):
 yy=36*mm-i*5.4*mm;txt(c,M,yy,label,7.2,'Bold');txt(c,20*mm,yy,body,6.9)
c.showPage()
page(c,11,'Every second matters','POINTS AND TIME')
y=para(c,M,89*mm,CW,'Your score starts at zero and rises with the original gameplay awards. Clear a stage to add a speed bonus: <b>100 points for each unused second</b> of its scoring allowance. Waiting never removes earned points.',7.4,10.3)
yy=y-7*mm
for i,(name,allow)in enumerate([('Axis Chemicals','8 minutes'),('Batmobile','5 minutes'),('Batcave','1 minute'),('Batwing','3 minutes'),('Cathedral','12 minutes')]):
 yrow=yy-i*5.5*mm;c.setFillColor(colors.HexColor('#E5DDCC')if i%2==0 else PAPER);c.rect(M,yrow-1.5*mm,CW,5.5*mm,fill=1,stroke=0);txt(c,M+2*mm,yrow,name,7.1);txt(c,52*mm,yrow,allow,7.1,'Bold')
y=para(c,M,yy-29*mm,CW,'<b>Example:</b> clear Axis Chemicals in five minutes: three unused minutes give an <b>18,000-point bonus</b>, plus your gameplay points.',7.1,9.3)
para(c,M,y-3*mm,CW,'Only active play counts toward this bonus clock. Pauses, menus, loading and cutscenes are excluded. Game over records eligible earned points, even on a partial run. Maximum score: 999,999.',6.9,9.0);c.showPage()
page(c,12,'Pick up where you left off','SAVING YOUR GAME')
y=para(c,M,89*mm,CW,'Press OPTION to pause. Select an item with Up/Down, then press A.',7.7,10.7)
for i,(a,b)in enumerate([('RESUME','Return to the action.'),('SAVE','Store the current checkpoint.'),('RESTART STAGE','Restart this stage; run time continues.'),('MAIN MENU','Leave play and record earned points.')]):
 yy=y-9*mm-i*12*mm;txt(c,M,yy,a,8.0,'Bold',GOLD);para(c,M,yy-3*mm,CW,b,7.2,9.8)
para(c,M,27*mm,CW,'Completing stages 1-4 automatically saves the next stage. After switching off and on, choose CONTINUE. Wait for the save confirmation before switching off. Finishing stage 5 stores your result and ends that saved run.',7.4,10.2);c.showPage()
page(c,13,'Records / Upload Best Score','MAKE YOUR MARK')
para(c,M,89*mm,CW,'Earn a positive eligible score, then open RECORDS and select UPLOAD BEST SCORE. A completed game is not required.',7.5,10.4)
for i,ch in enumerate('ABC'):
 x=(20+i*15)*mm;c.setFillColor(GOLD if i==1 else INK);c.roundRect(x,53*mm,11*mm,13*mm,1*mm,fill=1,stroke=0);txt(c,x+2.2*mm,56.2*mm,ch,18,'Mono',INK if i==1 else WHITE)
center(c,48.5*mm,'EDITING INITIAL 2',6.5,'Bold',DIM)
y=para(c,M,42*mm,CW,'<b>Left/Right:</b> choose an initial.<br/><b>Up/Down:</b> change its letter.<br/><b>Hold A + Up/Down:</b> scroll faster.<br/><b>OPTION:</b> generate your QR code.<br/><b>B:</b> go back.',7.5,11)
para(c,M,y-3*mm,CW,'Scan the displayed QR with your phone. The game code is BATMAN. Online submission depends on the leaderboard service being available.',7.1,9.8)
c.showPage()
page(c,14,'Records and extra options','A FRESH CHALLENGE')
y=para(c,M,89*mm,CW,'<b>Reset Records</b> asks for confirmation. Press A to clear your best and last scores, or B to cancel. The reset is saved; upload is unavailable while your best score is zero. Your game checkpoint is kept.',7.5,10.5)
txt(c,M,y-8*mm,'EXTRA OPTIONS',8.5,'Bold',GOLD)
y=para(c,M,y-12*mm,CW,'At the main menu, rotate the control stick clockwise through ten full turns to unlock cheat options. The options include invulnerability, frozen stage time and level select.',7.4,10.4)
y=para(c,M,y-4*mm,CW,'Unlocking cheats makes the run unranked, even when the individual toggles are OFF. Cold restart and begin a fresh normal game to qualify again.',7.3,10.2)
para(c,M,y-4*mm,CW,'Starting with more than three lives also disables points for that run. Extra lives earned normally during play are allowed.',7.3,10.2);c.showPage()
page(c,15,'Original game and this port','CREDITS')
credits=[('CODING','Mike Lamb / Jobbeeee / Shorty'),('GRAPHICS','Dawn Drake / Bill Harbison / John Palmer'),('MUSIC AND FX','Jon Dunn / Matthew Cannon'),('REVERSE ENGINEERING','MarkyTurtle'),('NGPC PORT','jajabinx35')]
for i,(a,b)in enumerate(credits):
 yy=(88-i*13)*mm;txt(c,M,yy,a,6.9,'Bold',GOLD);para(c,M,yy-3*mm,CW,b,7.2,9.7)
para(c,M,20*mm,CW,'Batman / DC Comics Inc. 1989. Original game: Ocean Software 1989. Neo Geo Pocket Color is an SNK platform. This is an unofficial fan port; original artwork, characters and music belong to their respective rights holders.',5.8,8.0,DIM);c.showPage()
c.setFillColor(INK);c.rect(0,0,W,H,fill=1,stroke=0);brand(c,0,H-9*mm,W,9*mm);c.drawImage(str(logo),6*mm,42*mm,69*mm,46*mm)
center(c,31*mm,'GOTHAM IS IN YOUR HANDS.',8,'Title',GOLD);center(c,22*mm,'BATMAN - THE MOVIE',8,'Bold',WHITE);center(c,14*mm,'PORTED BY JAJABINX35',6.8,'Bold',GOLD);center(c,7*mm,'NEO GEO POCKET COLOR / M64',5.5,'Body',WHITE);c.showPage();c.save()
assert min(v for page,v in bounds)>7.3*mm,('content below safe margin',[(page,round(v/mm,2))for page,v in bounds if v<=7.3*mm])
# Exact-size booklet spreads, imposed on A4 landscape; no resizing of pages.
reader=PdfReader(manual);writer=PdfWriter();AW,AH=297*mm,210*mm;sx=(AW-2*W)/2;sy=(AH-H)/2
def guides(label):
 b=BytesIO();g=canvas.Canvas(b,pagesize=(AW,AH));g.setStrokeColor(colors.HexColor('#555555'));g.setLineWidth(.3)
 for xx in [sx,sx+2*W]:
  for yy in [sy,sy+H]:g.line(xx-3*mm,yy,xx-mm,yy);g.line(xx+mm,yy,xx+3*mm,yy);g.line(xx,yy-3*mm,xx,yy-mm);g.line(xx,yy+mm,xx,yy+3*mm)
 g.setDash(2,2);g.line(sx+W,sy-5*mm,sx+W,sy-mm);g.line(sx+W,sy+H+mm,sx+W,sy+H+5*mm);g.setDash()
 txt(g,15*mm,AH-14*mm,label,8,'Bold');txt(g,15*mm,12*mm,'Print at 100% / Actual size. Duplex: flip on short edge. Trim outer marks, then fold at centre.',7,'Body')
 g.setLineWidth(.7);g.line(220*mm,13*mm,270*mm,13*mm);txt(g,231*mm,16*mm,'50 mm check',6.5,'Body');g.save();return PdfReader(b).pages[0]
for sheet in range(4):
 for side,(left,right)in enumerate([(15-2*sheet,2*sheet),(2*sheet+1,14-2*sheet)]):
  p=writer.add_blank_page(width=AW,height=AH);p.merge_transformed_page(reader.pages[left],Transformation().translate(sx,sy));p.merge_transformed_page(reader.pages[right],Transformation().translate(sx+W,sy));p.merge_page(guides(f'BATMAN / SHEET {sheet+1} / '+('FRONT'if side==0 else'BACK')))
with(O/'Batman_NGPC_Manual_A4_Booklet_Print.pdf').open('wb')as f:writer.write(f)
# 230 x 116 mm PAL clamshell wrap: back 105, spine 20, front 105.
case=O/'Batman_NGPC_Case_Insert_A4_Print.pdf';c=canvas.Canvas(str(case),pagesize=(AW,AH));c.setTitle('Batman NGPC - 230 x 116 mm PAL case insert');cx=(AW-230*mm)/2;cy=(AH-116*mm)/2
c.setFillColor(colors.black);c.rect(cx-3*mm,cy-3*mm,236*mm,122*mm,fill=1,stroke=0)
cover(c,cx+125*mm,cy,105*mm,116*mm)
# Back panel.
txt(c,cx+7*mm,cy+103*mm,'FIVE STAGES. ONE DARK KNIGHT.',10.5,'Title',GOLD)
para(c,cx+7*mm,cy+96*mm,91*mm,'From Axis Chemicals to Gotham Cathedral, the original movie adventure comes to Neo Geo Pocket Color. Platform action, high-speed roads, Batcave deduction and a battle over the city.',8.2,11,WHITE)
for i,n in enumerate([1,2,4]):c.drawImage(str(shots[n]),cx+(7+i*31)*mm,cy+44*mm,28*mm,26.6*mm)
txt(c,cx+7*mm,cy+36*mm,'SAVE / CONTINUE - RECORDS - BATMAN QR',7.5,'Bold',GOLD)
para(c,cx+7*mm,cy+30*mm,91*mm,'Original game: Ocean Software 1989. Batman / DC Comics Inc. 1989. NGPC port by jajabinx35. Reverse engineering by MarkyTurtle. Unofficial fan port.',6.7,9.3,WHITE)
txt(c,cx+7*mm,cy+7*mm,'NEO GEO POCKET COLOR',8,'Bold',GOLD)
# Spine.
c.setFillColor(GOLD);c.rect(cx+105*mm,cy,20*mm,116*mm,fill=1,stroke=0);c.saveState();c.translate(cx+117*mm,cy+58*mm);c.rotate(90);center(c,-2*mm,'BATMAN - THE MOVIE',12,'Title',INK,100*mm,-50*mm);c.restoreState()
for xx in [cx,cx+230*mm]:
 for yy in [cy,cy+116*mm]:c.setStrokeColor(INK);c.setLineWidth(.3);c.line(xx-6*mm,yy,xx-3.5*mm,yy);c.line(xx+3.5*mm,yy,xx+6*mm,yy);c.line(xx,yy-6*mm,xx,yy-3.5*mm);c.line(xx,yy+3.5*mm,xx,yy+6*mm)
for xx in [cx+105*mm,cx+125*mm]:c.setDash(2,2);c.line(xx,cy-7*mm,xx,cy-3.5*mm);c.line(xx,cy+119.5*mm,xx,cy+123*mm);c.setDash()
txt(c,15*mm,AH-12*mm,'BATMAN / PAL CLAMSHELL INSERT / 230 x 116 mm',8,'Bold');txt(c,15*mm,12*mm,'Actual size / 100%. Trim at marks. Spine folds: 105 mm and 125 mm from left trim. Test fit before final stock.',7,'Body');c.save()
r=PdfReader(case);p=r.pages[0];p.mediabox=RectangleObject([cx+125*mm,cy,cx+230*mm,cy+116*mm]);p.cropbox=p.mediabox;w=PdfWriter();w.add_page(p)
with(T/'case_front.pdf').open('wb')as f:w.write(f)
spec={'manual_trim_mm':[81,110],'manual_pages':16,'booklet_sheets':4,'booklet_print_pdf_pages':8,'case_wrap_trim_mm':[230,116],'case_panel_widths_mm':[105,20,105],'case_bleed_mm':3,'manual_bleed_mm':0,'manual_size_basis':'Measured original PAL SNK vs. Capcom manual PDF: page widths 80.518-81.026 mm and heights 109.432-109.813 mm for first four pages; nominal trim rounded to 81 x 110 mm. Not a universal manufacturer specification for every regional manual.','manual_reference':'https://www.gamingalexandria.com/wp/2025/12/snk-vs-capcom-the-match-of-the-millennium/','case_reference':'https://www.gamopat-forum.com/t49219-inserts-neo-geo-pockets-dimensions','original_art':'User-supplied 258144.jpg; game-native stage captures. No newly imagined Batman illustration.'}
(O/'PRINT_SPECIFICATIONS.json').write_text(json.dumps(spec,indent=2)+'\n')
(O/'PRINTING_README.md').write_text('''# Batman NGPC print kit

The reader manual has 16 pages at exactly **81 x 110 mm**. This nominal size follows the measured pages of an original PAL manual scan, rather than assuming all regional releases use the same format. The original reference and dimensional evidence are in PRINT_SPECIFICATIONS.json. Artwork uses the original gold Batman emblem supplied with the game and actual native gameplay captures.

For home booklet printing, use Batman_NGPC_Manual_A4_Booklet_Print.pdf: A4 landscape, Actual Size / 100%, duplex with **flip on short edge**. Print a test sheet and check the 50 mm line. Trim each sheet to the outer crop marks, keep sheets 1-4 nested in order, fold on the centre marks and saddle-staple. Finished booklet: 81 x 110 mm. Use approximately 90-120 gsm inner stock and a slightly heavier cover if your printer supports it. Do not choose Fit to Page.

The PAL clamshell wrap is **230 x 116 mm**, with 105 mm back, 20 mm spine and 105 mm front panels, plus 3 mm bleed. Print the A4 case insert at 100%, check a plain-paper test against your own case, then trim. Case molds and regional packaging differ, so the included crop/fold marks are preferable to a percentage guess. These are print layouts, not a photograph of a manufactured product. The requested generated case-and-manual display photo could not be produced because the image-generation service rejected it.

Original manual scan reference: https://www.gamingalexandria.com/wp/2025/12/snk-vs-capcom-the-match-of-the-millennium/
First-hand PAL insert measurement reference: https://www.gamopat-forum.com/t49219-inserts-neo-geo-pockets-dimensions
''')
print('PRINT KIT READY',manual)
