
USE online_sale;
GO

CREATE TABLE online_store(
	name_store VARCHAR(64) NOT NULL,
	email VARCHAR(50) PRIMARY KEY NOT NULL,
	paymant_for_Delivery VARCHAR(15) NOT NULL,
	quantity_product int NOT NULL
);

CREATE TABLE product(
	product_name VARCHAR(100) NOT NULL,
	id_product INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	firm VARCHAR(32) NOT NULL,
	model VARCHAR(32) NOT NULL,
	technical_specifications VARCHAR(MAX),
	price INT NOT NULL,
	Warranty_period VARCHAR(32) NOT NULL,
	quantity INT NOT NULL
);

CREATE TABLE client(
	id_client INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	name_client VARCHAR(128) NOT NULL,
	address_client VARCHAR(150) NOT NULL,
	phone_number VARCHAR(255) 
); 
CREATE TABLE product_order(
	order_number INT PRIMARY KEY NOT NULL,
	id_client INT IDENTITY(1,1) NOT NULL,
	product_name VARCHAR(100) NOT NULL,
	name_store VARCHAR(64) NOT NULL,
	number_of_products INT NOT NULL,
	order_date DATE NOT NULL,
	order_status VARCHAR(15)
	
);
CREATE TABLE delivery(
	order_number INT NOT NULL,
	delivery_date DATE NOT NULL,
	delivery_time TIME NOT NULL,
	delivery_address VARCHAR(100) NOT NULL,
	name_courier VARCHAR(64) NOT NULL,
	PRIMARY KEY (name_courier, delivery_time),
);
