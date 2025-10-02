USE online_sales;
GO

CREATE TABLE online_stores
(
	name_store VARCHAR(64) PRIMARY KEY NOT NULL,
	email VARCHAR(50) CHECK(email LIKE '_%@_%._%') NOT NULL,
	paymant_for_Delivery BIT NOT NULL,
);

CREATE TABLE product(
	product_name VARCHAR(50) NOT NULL,
	id_product INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	firm VARCHAR(32) NOT NULL,
	model VARCHAR(32) NOT NULL,
	technical_specifications VARCHAR(MAX) ,
	price INT NOT NULL,
	Warranty_period DATE NOT NULL,
);

CREATE TABLE client(
	id_client INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	name_client VARCHAR(64) NOT NULL,
	address_client VARCHAR(50) NOT NULL,
	phone_number VARCHAR(11) CHECK (phone_number LIKE '[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')
); 
CREATE TABLE product_order(
	order_number INT PRIMARY KEY NOT NULL,
	id_client INT IDENTITY (1,1) NOT NULL,
	store_names VARCHAR(64) NOT NULL,
	number_of_products INT NOT NULL,
	order_date DATETIME NOT NULL,
	order_status VARCHAR(10) CHECK(order_status IN ('¬€ƒ¿Õ', 'Œ“Ã≈Õ≈Õ','¬ œ”“»'))
);
CREATE TABLE delivery(
	order_number INT PRIMARY KEY NOT NULL,
	delivery_date DATE NOT NULL,
	delivery_time TIME NOT NULL,
	delivery_address VARCHAR(100) NOT NULL,
	name_courier VARCHAR(64) NOT NULL,
);
