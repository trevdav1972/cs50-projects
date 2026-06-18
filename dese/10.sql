-- Write a SQL query to find the 10 public school with the highest per-pupil expenditures --
-- My query should return the names of the districts and the highest per-pupil expenditures --

SELECT name, per_pupil_expenditure FROM districts
JOIN expenditures ON districts.id = expenditures.district_id
WHERE type LIKE "Public School%"
ORDER BY per_pupil_expenditure DESC
LIMIT 10;
