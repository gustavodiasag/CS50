-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Here I'm searching for information about the crime and find out the time of the theft and that there are some witnesses' interviews
SELECT description FROM crime_scene_reports
WHERE year = 2020 AND day = 28 AND month = 7 AND street = "Chamberlin Street";

-- Here I get three main pieces of information:
-- 1: I can access the parking lot security logs to check for any car that left after the theft occured
-- 2: The thief was recognized in an ATM on "Fifer Street" withdrawing some money
-- 3: The thief called someone for a few seconds saying that he/she is going to leave the town on the first flight of 07/29
SELECT transcript FROM interviews
WHERE year = 2020 AND day = 28 AND month = 7;

-- Here I get all the names of the people that left the courthouse during the robbery via their license_plate information
-- Suspects = Danielle, Roger, Elizabeth, Russel, Evelyn
SELECT name, hour, minute FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit" ORDER BY minute;

-- Here I'm checking for every withdraw that ocurred during the day of the crime and the name of the person who did it
-- Suspects = Ernest, Danielle, Elizabeth, Russell
SELECT atm_transactions.account_number, name, atm_transactions.day FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
WHERE transaction_type = "withdraw" AND courthouse_security_logs.year = 2020
AND courthouse_security_logs.month = 7 AND courthouse_security_logs.day = 28 AND hour = 10 AND activity = "exit" ORDER BY minute;

-- Here I look for all the people that left the town the next day, and see if it matches my suspects list
-- Suspects = Ernest, Danielle
SELECT name, hour, minute, city FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id = airports.id
WHERE passengers.flight_id IN
(SELECT id FROM flights WHERE year = 2020 AND  month = 7 AND day = 29) ORDER BY hour, minute;

-- Lastly I look through each suspect's phone calls and determine the thief
SELECT name, duration FROM phone_calls
JOIN people ON phone_calls.receiver = people.phone_number WHERE
year = 2020 AND month = 7 AND day = 28 AND caller IN
(SELECT phone_number FROM people WHERE name = "");

-- Thief = Ernest
-- Place = London
-- Accomplice = Berthold
