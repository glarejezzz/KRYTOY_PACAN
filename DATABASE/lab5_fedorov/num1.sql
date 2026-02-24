CREATE VIEW vw_online_store
AS SELECT os.name_store, os.email, os.paymant_for_Delivery, os.quantity_product FROM online_store os

GO

CREATE VIEW vw_product
AS SELECT p.product_name, p.firm, p.model, p.technical_specifications, p.price, p.Warranty_period,p.quantity from product p

go

CREATE VIEW vw_client
AS SELECT c.id_client ,c.name_client , c.address_client, c.phone_number FROM client c

go

CREATE VIEW vw_product_order
AS SELECT c.id_client,d.order_number, os.name_store, po.number_of_products, po.order_date, po.order_status FROM product_order po
JOIN delivery d ON po.order_number = d.order_number
JOIN client c ON po.id_client = c.id_client
JOIN online_store os ON po.name_store = os.name_store

go

CREATE VIEW vw_delivery 
AS SELECT d.order_number,d.delivery_date ,d.delivery_time , d. delivery_address,d.name_courier FROM delivery d;