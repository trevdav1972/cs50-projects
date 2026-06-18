CREATE TABLE Users (
    "id" INTEGER,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    "username" TEXT NOT NULL,
    "password" TEXT NOT NULL,
    PRIMARY KEY ("id")
);
CREATE TABLE Schools_and_Universities (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "type" TEXT NOT NULL CHECK ("type" IN ("Elementary School", "Middle School", "High School", "Lower School", "Upper School", "College", "University")),
    "location" TEXT NOT NULL,
    "year_founded" INTEGER NOT NULL,
    PRIMARY KEY ("id")
);
CREATE TABLE Companies (
    "id" INTEGER,
    "name" TEXT NOT NULL UNIQUE,
    "industry",
    "location" TEXT NOT NULL,
    PRIMARY KEY ("id")
);
CREATE TABLE Connections (
    "id" INTEGER,
    "user_id" INTEGER,
    "school_id" INTEGER,
    "company_id" INTEGER,
    "related_id" INTEGER NOT NULL,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("user_id") REFERENCES "Users"("id")
    FOREIGN KEY ("school_id") REFERENCES "Schools_and_Universities"("id")
    FOREIGN KEY ("company_id") REFERENCES "Companies"("id")
);
