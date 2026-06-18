SELECT salary, first_name, last_name FROM salaries
JOIN players ON salaries.player_id = players.id
WHERE year = '2001'
ORDER BY salary ASC, first_name, last_name, player_id LIMIT 50;
