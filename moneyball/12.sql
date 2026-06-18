SELECT first_name, last_name
FROM (
    SELECT id, first_name, last_name
    FROM (
        SELECT players.id, first_name, last_name
        FROM players
        JOIN performances ON players.id = performances.player_id
        JOIN salaries ON players.id = salaries.player_id
        WHERE performances.year = salaries.year AND performances.H != 0 AND salaries.year = 2001
        ORDER BY salaries.salary / performances.H
        LIMIT 10
    )

    INTERSECT

    SELECT id, first_name, last_name
    FROM (
        SELECT players.id, first_name, last_name
        FROM players
        JOIN performances ON players.id = performances.player_id
        JOIN salaries ON players.id = salaries.player_id
        WHERE performances.year = salaries.year
          AND performances.RBI != 0
          AND salaries.year = 2001
        ORDER BY salaries.salary / performances.RBI
        LIMIT 10
    )
)
ORDER BY id;
