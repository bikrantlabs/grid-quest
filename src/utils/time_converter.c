#include "time_converter.h"
int convert_to_seconds(int minutes, int seconds) {
  return minutes * 60 + seconds;
}
Time *convert_to_minutes(int seconds) {
  Time *time;
  time->minutes = seconds / 60;
  time->seconds = seconds % 60;
  return time;
}