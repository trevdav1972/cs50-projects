SELECT districts.name, SUM(expenditures.pupils)
FROM expenditures
JOIN districts ON districts.id = expenditures.district_id
GROUP BY districts.name;
