#ifndef BATMAN_VIDEO_H
#define BATMAN_VIDEO_H
#include "game.h"
extern u16 camera_x,camera_y,video_tile_writes,video_sprite_count;
extern u16 video_max_sprites,video_overflows,video_background_reloads;
void video_title_load(void);
void video_title_fade(u8 value);
void video_title_reveal(u8 rows);
void video_menu(u8 choice);
void video_menu_update(u8 choice);
void video_controls(u8 audio_on);
void video_credits(void);
void video_start_game(void);
void video_game(void);
void video_present(void);
u8 video_bitmap_available(void);
void video_bitmap_publish(void);
extern u16 video_present_count;
extern volatile u8 video_present_ready;
void video_pause(u8 choice);
void video_pause_update(u8 choice);
void video_resume(void);
void video_over(void);
void video_stage_complete(u8 page);
void video_options(u8 choice);void video_records(u8 choice);void video_stage_records(u8 choice);
void video_options_update(u8 choice);void video_records_update(u8 choice);
void video_qr_entry_update(void);
void video_records_reset(void);void video_qr_entry(void);void video_qr_generating(void);void video_qr_show(u8 ok);void video_logo(void);
void video_ending_start(void);void video_ending_render(u16 time_frames);
void video_intro_render(u16 time_frames);void video_stage_intro(void);void video_credits_page(u8 page);void video_pause_status(u8 ok);
#endif
