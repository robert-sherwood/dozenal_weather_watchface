#include "main_window.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_bitham_42_light;
static GFont s_res_gothic_28;
static TextLayer *time_layer;
static TextLayer *date_layer;
static InverterLayer *inverter_layer;
static TextLayer *temp_layer;
static BitmapLayer *s_bitmaplayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, 1);
  
  s_res_bitham_42_light = fonts_get_system_font(FONT_KEY_BITHAM_42_LIGHT);
  s_res_gothic_28 = fonts_get_system_font(FONT_KEY_GOTHIC_28);
  // time_layer
  time_layer = text_layer_create(GRect(7, 7, 132, 51));
  text_layer_set_background_color(time_layer, GColorBlack);
  text_layer_set_text_color(time_layer, GColorWhite);
  text_layer_set_text(time_layer, "12:XE");
  text_layer_set_text_alignment(time_layer, GTextAlignmentCenter);
  text_layer_set_font(time_layer, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)time_layer);
  
  // date_layer
  date_layer = text_layer_create(GRect(6, 62, 133, 33));
  text_layer_set_background_color(date_layer, GColorBlack);
  text_layer_set_text_color(date_layer, GColorWhite);
  text_layer_set_text(date_layer, "Day DD");
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
  text_layer_set_font(date_layer, s_res_gothic_28);
  layer_add_child(window_get_root_layer(s_window), (Layer *)date_layer);
  
  // inverter_layer
  inverter_layer = inverter_layer_create(GRect(0, 98, 143, 72));
  layer_add_child(window_get_root_layer(s_window), (Layer *)inverter_layer);
  
  // temp_layer
  temp_layer = text_layer_create(GRect(4, 107, 87, 50));
  text_layer_set_text(temp_layer, "XXX");
  text_layer_set_font(temp_layer, s_res_bitham_42_light);
  layer_add_child(window_get_root_layer(s_window), (Layer *)temp_layer);
  
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(20, 20, 40, 40));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(time_layer);
  text_layer_destroy(date_layer);
  inverter_layer_destroy(inverter_layer);
  text_layer_destroy(temp_layer);
  bitmap_layer_destroy(s_bitmaplayer_1);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main_window(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}
