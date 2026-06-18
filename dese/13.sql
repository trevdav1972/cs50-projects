SELECT districts.name, schools.type FROM districts
JOIN schools ON districts.id = schools.district_id
WHERE schools.type LIKE "Public School%"
LIMIT 10;
