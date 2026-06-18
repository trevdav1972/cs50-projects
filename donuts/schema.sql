CREATE TABLE Ingredients (
    "id" INTEGER,
    "name" TEXT NOT NULL UNIQUE,
    "unit" TEXT NOT NULL CHECK("unit" IN ("pdounds", "grams", "liters")),
    PRIMARY KEY ("id")
);

CREATE TABLE Donuts (
    "id" INTEGER,
    "ingredient_id" INTEGER,
    "name" TEXT NOT NULL UNIQUE,
    "gluten_free" BOOLEAN NOT NULL,
    "price_per_donut" REAL NOT NULL,
    FOREIGN KEY ("ingredient_id") REFERENCES "Ingredients"("id"),
    PRIMARY KEY ("id")
);

CREATE TABLE Orders (
    "id" INTEGER,
    "customer_id" INTEGER,
    "order_number" INTEGER NOT NULL,
    PRIMARY KEY ("id"),
    FOREIGN KEY ("customer_id") REFERENCES "customers"("id")
);

CREATE TABLE OrdersDonuts (
    "order_id" INTEGER,
    "donut_id" INTEGER,
    "quantity" INTEGER NOT NULL,
    PRIMARY KEY ("order_id", "donut_id"),
    FOREIGN KEY ("order_id") REFERENCES "Orders"("id"),
    FOREIGN KEY ("donut_id") REFERENCES "Donuts"("id")
);

CREATE TABLE Customers (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "email" TEXT NOT NULL UNIQUE,
    PRIMARY KEY ("id")
);
