USE online_sale

GO

CREATE TABLE online_store(
	name_store VARCHAR(64) PRIMARY KEY NOT NULL,
	email VARCHAR(50) CHECK (email LIKE '_%@_%._%') NOT NULL,
	paymant_for_Delivery VARCHAR(3) NOT NULL,
	quantity_product int NOT NULL,


);

CREATE TABLE product(
	id_product INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	product_name VARCHAR(50) NOT NULL,
	firm VARCHAR(32) NOT NULL,
	model VARCHAR(32) NOT NULL,
	technical_specifications VARCHAR(MAX),
	price INT NOT NULL,
	Warranty_period VARCHAR(32) NOT NULL,
	quantity INT NOT NULL,
	number_of_view VARCHAR(255) NOT NULL,
	adding_cart VARCHAR(255) NOT NULL,
	completed_order INT NOT NULL,
	);

CREATE TABLE client(
	id_client INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	name_client VARCHAR(64) NOT NULL,
	address_client VARCHAR(255) NOT NULL,
	phone_number VARCHAR(255) CHECK (phone_number LIKE '+[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]')
); 
CREATE TABLE product_order(
	id_client INT IDENTITY (1,1) NOT NULL,
	name_product varchar(50) not null,
	order_number INT  NOT NULL,
	name_store VARCHAR(64) NOT NULL,
	number_of_products INT NOT NULL,
	order_date VARCHAR(32) NOT NULL,
	order_status VARCHAR(15) CHECK(order_status IN ('бшдюм', 'нрлемем','б осрх','ондрбепфдем')),
	PRIMARY KEY (id_client, order_number)
	
);
CREATE TABLE delivery(
	order_number INT  NOT NULL,
	delivery_date DATE NOT NULL,
	delivery_time TIME NOT NULL,
	delivery_address VARCHAR(250) NOT NULL,
	name_courier VARCHAR(64) NOT NULL,
	PRIMARY KEY (delivery_date, order_number),
	
);
