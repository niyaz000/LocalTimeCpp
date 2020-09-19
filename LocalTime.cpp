#include "LocalTime.h"

#include <iostream>

void validateTime(int64_t hour, int64_t minute, int64_t second) {
  if (hour > 23 || hour < 0) {
    throw std::out_of_range("hour should be between (0, 23) inclusive");
  }
  if (minute > 59 || minute < 0) {
    throw std::out_of_range("minute should be between (0, 59) inclusive");
  }
  if (second > 59 || second < 0) {
    throw std::out_of_range("second should be between (0, 59) inclusive");
  }
}

int64_t to_hour(int64_t epoch_time) {
  return (epoch_time/(60 * 60)) % 24;
}

int64_t to_minute(int64_t epoch_time) {
  return (epoch_time/60) % 60;
}

int64_t to_second(int64_t epoch_time) {
  return (epoch_time) % 60;
}

LocalTime::LocalTime(int64_t hour, int64_t minute, int64_t second):
  hour(hour),
  minute(minute),
  second(second),
  nano_second(0) {
  validateTime(hour, minute, second);
}

LocalTime::LocalTime(int64_t hour,
                     int64_t minute,
                     int64_t second,
                     int64_t nano_second) :
  hour(hour),
  minute(minute),
  second(second),
  nano_second(nano_second) {

}

LocalTime::LocalTime(int64_t epoch_time, int64_t nano_second):
  hour(to_hour(epoch_time)),

  minute(to_minute(epoch_time)),

  second(to_second(epoch_time)),

  nano_second(nano_second) {

}

int64_t LocalTime::get_hour() const {
  return this->hour;
}

int64_t LocalTime::get_minute() const {
  return this->minute;
}

int64_t LocalTime::get_second() const {
  return this->second;
}

int64_t LocalTime::to_nanosecond() const {
  return ((this->hour * 60 * 60) + (this->minute * 60) + this->second) * 1000000000;
}

LocalTime LocalTime::with(int64_t hour) {
  return {hour, 0, 0};
}

LocalTime LocalTime::with(int64_t hour, int64_t minute) {
  return {hour, minute, 0};
}

LocalTime LocalTime::with(int64_t hour, int64_t minute, int64_t second) {
  return {hour, minute, second};
}

LocalTime LocalTime::plus_hour(int64_t hour) {
  return {this->hour + hour, this->minute, this->second, this->nano_second};
}

LocalTime LocalTime::minus_hour(int64_t hour) {
  return {(this->hour - hour) % 24, this->minute, this->second, this->nano_second};
}

LocalTime LocalTime::withHour(int64_t hour) {
  return {hour, this->minute, this->second, this->nano_second};
}

LocalTime LocalTime::withMinute(int64_t minute) {
  return {this->hour, minute, this->second, this->nano_second};
}

LocalTime LocalTime::withSecond(int64_t second) {
  return {this->hour, this->minute, second, this->nano_second};
}
