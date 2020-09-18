#include "LocalTime.h"

#include <iostream>

void validateTime(int64_t hour, int64_t minute, int64_t second) {
  if (hour > 23 || hour < 0) {
    throw std::out_of_range("hour should be between (0, 23) inclusive");
  }
  if(minute > 59 || minute < 0) {
    throw std::out_of_range("minute should be between (0, 59) inclusive");
  }
  if(second > 59 || second < 0) {
    throw std::out_of_range("second should be between (0, 59) inclusive");
  }
}

LocalTime::LocalTime(int64_t hour, int64_t minute, int64_t second): hour(hour), minute(minute), second(second), nano_second(0) {
  validateTime(hour, minute, second);
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
  return LocalTime(hour, 0, 0);
}

LocalTime LocalTime::with(int64_t hour, int64_t minute) {
  return LocalTime(hour, minute, 0);
}

LocalTime LocalTime::with(int64_t hour, int64_t minute, int64_t second) {
  return LocalTime(hour, minute, second);
}

LocalTime LocalTime::plus_hour(int64_t hour) {
  return LocalTime(this->hour + hour, this->minute, this->second);
}

LocalTime LocalTime::minus_hour(int64_t hour) {
  return LocalTime(this->hour - hour, this->minute, this->second);
}
