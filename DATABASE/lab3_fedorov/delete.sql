USE online_sales

GO

DELETE FROM product_order
WHERE order_status = 'ме ондрбепфдемн'
AND order_date < '2025-11-19';

DELETE FROM delivery
where order_number = '0';

DELETE FROM product 
WHERE quantity = '0';

DELETE FROM  online_store
where quantity_product = '0';

DELETE FROM  product_order
where number_of_products <= 0;