USE online_sale;

GO

ALTER TABLE online_store ADD CONSTRAINT chk_email CHECK(email LIKE '_%@_%._%');
ALTER TABLE client ADD CONSTRAINT chk_phone_number CHECK (phone_number LIKE '+[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]');
ALTER TABLE product_order ADD CONSTRAINT chk_order_status CHECK(order_status IN ('бшдюм', 'нрлемем','б осрх','ондрбепфдем'));
ALTER TABLE product_order ADD CONSTRAINT fk_name_store FOREIGN KEY(name_store)REFERENCES online_store (name_store);
ALTER TABLE delivery ADD CONSTRAINT fk_product_order FOREIGN KEY (order_number) REFERENCES product_order(order_number);