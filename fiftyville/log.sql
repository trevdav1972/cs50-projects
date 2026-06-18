-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
    Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    Interviews were conducted today with three witnesses who were present at the time –
    each of their interview transcripts mentions the bakery.

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%'; // This gives back what the witnesses said
| 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma''s bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25; // This gives back potential suspects licenseplates, and I got them from knowing the day year month, and minute and hour.

SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25);

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 10;

SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60 AND caller IN (SELECT phone_number FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25)));

SELECT * FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE destination_airport_id = 4 AND year = 2021 AND month = 7 AND day = 29);

SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';
SELECT people.* FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number IN (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street');

SOFIA KELSEY BRUCE