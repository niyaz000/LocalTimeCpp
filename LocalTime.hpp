#ifndef V1_LOCALTIME_H
#define V1_LOCALTIME_H

#include <stdint.h>

class LocalTime {

private:
  const int64_t hour;
  const int64_t minute;
  const int64_t second;
  const int64_t nano_second;

  LocalTime(int64_t hour, int64_t minute, int64_t second);

public:
  static LocalTime with(int64_t hour);
  static LocalTime with(int64_t hour, int64_t minute);
  static LocalTime with(int64_t hour, int64_t minute, int64_t second);

  int64_t get_hour() const;
  int64_t get_minute() const;
  int64_t get_second() const;
  int64_t to_nanosecond() const;

  LocalTime plus_hour(int64_t hour);
  LocalTime minus_hour(int64_t hour);

};

#endif //V1_LOCALTIME_H
