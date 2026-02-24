use online_sale
go

CREATE VIEW vw_online_sale
AS SELECT 
os.name_store,
os.email,
os.paymant_for_Delivery, 
os.quantity_product,
p.id_product,
p.firm,
p.model,
p.technical_specifications,
p.price,
p.Warranty_period,
p.quantity,
c.name_client, 
c.address_client, 
c.phone_number,
c.id_client,
p.product_name, 
po.number_of_products, 
po.order_date, 
po.order_status,
d.order_number,
d.delivery_date,
d.delivery_time,
d.delivery_address,
d.name_courier
FROM product_order po
LEFT JOIN delivery d ON po.order_number = d.order_number
INNER JOIN client c ON po.id_client = c.id_client
INNER JOIN online_store os ON po.name_store = os.name_store
INNER JOIN product p ON po.name_product = p.product_name

go

UPDATE product_order
SET order_date  = '2024-01-14'
WHERE name_store = 'ֲאיכהבוננטח';