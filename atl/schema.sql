CREATE TABLE passengers (
    "id" INTEGER,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    "age" INTEGER NOT NULL,
    PRIMARY KEY ("id")
);

CREATE TABLE Check_Ins (
    "passenger_id" INTEGER,
    "datetime" NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY("passenger_id") REFERENCES "passengers"("id")
);

CREATE TABLE Airlines (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "concourse" TEXT NOT NULL CHECK("concourse" IN ('A', 'B', 'C', 'D', 'E', 'F', 'T')),
    PRIMARY KEY ("id")
);

CREATE TABLE Flights (
    "id" INTEGER,
    "airline_id" INTEGER,
    "flight_number" NUMERIC NOT NULL UNIQUE,
    FOREIGN KEY ("airline_id") REFERENCES "Airlines"("id")
    PRIMARY KEY ("id")
);
