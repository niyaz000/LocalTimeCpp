//
// Created by Niyaz Kalathil on 18/09/20.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "LocalTime.h"


TEST_CASE("LocalTime tests") {

  SECTION( "Given localTime created with hour alone should set minute and second to zero" ) {
    auto local_time = LocalTime::with(10);
    REQUIRE( local_time.get_hour() == 10);
    REQUIRE( local_time.get_minute() == 0);
    REQUIRE( local_time.get_second() == 0);
  }

  SECTION( "Given localTime created with hour and minute, should set second to zero" ) {
    auto local_time = LocalTime::with(10, 8);
    REQUIRE( local_time.get_hour() == 10);
    REQUIRE( local_time.get_minute() == 8);
    REQUIRE( local_time.get_second() == 0);
  }

  SECTION( "Given localTime created with hour and minute and second should values correctly" ) {
    auto local_time = LocalTime::with(10, 8, 9);
    REQUIRE( local_time.get_hour() == 10);
    REQUIRE( local_time.get_minute() == 8);
    REQUIRE( local_time.get_second() == 9);
  }

  SECTION("Given LocalTime created with invalid hour should throw out_of_range exception") {
    REQUIRE_THROWS_AS(LocalTime::with(-1), std::out_of_range);
    REQUIRE_THROWS_AS(LocalTime::with(-1, 0), std::out_of_range);
    REQUIRE_THROWS_AS(LocalTime::with(-1, 0, 0), std::out_of_range);
  }

  SECTION("Given LocalTime created with invalid minute should throw out_of_range exception") {
    REQUIRE_THROWS_AS(LocalTime::with(20, -1), std::out_of_range);
    REQUIRE_THROWS_AS(LocalTime::with(10, -1, 0), std::out_of_range);
  }

  SECTION("Given LocalTime created with invalid second should throw out_of_range exception") {
    REQUIRE_THROWS_AS(LocalTime::with(1, 10, -1), std::out_of_range);
  }

  SECTION("plus_hour : given adding hour greater than allowed limit, should throw exception") {
    auto local_time = LocalTime::with(10);
    REQUIRE_THROWS_AS(local_time.plus_hour(20), std::out_of_range);
  }

  SECTION("plus_hour : given adding hour within the allowed limit, should add new value to the hour") {
    auto local_time = LocalTime::with(10);
    auto updated_time = local_time.plus_hour(3);
    REQUIRE(updated_time.get_hour() == 13);
  }

}

