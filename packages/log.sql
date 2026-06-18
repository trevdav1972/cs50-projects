
-- *** The Lost Letter ***
SELECT * FROM addresses WHERE address = '900 Somerville Avenue';
SELECT * FROM packages WHERE "from_address_id" = (SELECT id FROM addresses WHERE address = '900 Somerville Avenue');
SELECT * FROM addresses WHERE id = 854;
-- *** The Devious Delivery ***
SELECT id FROM packages WHERE from_address_id IS NULL;
SELECT * FROM packages WHERE from_address_id IS NULL;

SELECT * FROM scans where "package_id" = (
    SELECT id FROM packages WHERE from_address_id IS NULL
) AND action = 'Drop';

SELECT type FROM addresses WHERE id = (
    SELECT address_id FROM scans WHERE "package_id" = (
        SELECT id FROM packages WHERE from_address_id IS NULL
    ) AND action = 'Drop'
 );

-- *** The Forgotten Gift ***

-- FROM id -- 9873
SELECT id FROM addresses WHERE address = '109 Tileston Street';


-- To id -- 4983
SELECT id FROM addresses WHERE address = '728 Maple Place';

-- contents in the package -- Flowers
SELECT contents FROM packages WHERE from_address_id = (
    SELECT id FROM addresses WHERE address = '109 Tileston Street'
) AND to_address_id = (
    SELECT id FROM addresses WHERE address = '728 Maple Place'
);

SELECT id FROM packages WHERE from_address_id = (
    SELECT id FROM addresses WHERE address = '109 Tileston Street'
) AND to_address_id = (
    SELECT id FROM addresses WHERE address = '728 Maple Place'
);
