SELECT schools.name, graduated, per_pupil_expenditure FROM districts
JOIN schools ON districts.id = schools.district_id
JOIN graduation_rates ON graduation_rates.school_id = schools.id
JOIN expenditures ON expenditures.district_id = districts.id
ORDER BY per_pupil_expenditure DESC, schools.name;
