SELECT name FROM people
WHERE people.id IN  (
SELECT people.id FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN (SELECT movies.id FROM movies
JOIN stars ON stars.movie_id = movies.id
WHERE stars.person_id IN (SELECT id FROM people WHERE birth = 1958 AND name = 'Kevin Bacon')
))
AND people.id NOT IN
(SELECT id FROM people WHERE birth = 1958 and name = 'Kevin Bacon')