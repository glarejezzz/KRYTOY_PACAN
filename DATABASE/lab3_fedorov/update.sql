USE online_sales

GO

UPDATE product 
SET price = price * 1.05 
WHERE product_name = 'сРЧЦ';


UPDATE online_store
SET email='Techbuy@mail.ru'
WHERE name_store= 'TechBuy';

UPDATE product_order
SET order_status= 'ондрбепфдем'
WHERE order_date < '2025-11-16'

UPDATE product
SET Warranty_period = '24 ЛЕЯЪЖЮ'
WHERE firm = 'Philips' 

UPDATE online_store
SET paymant_for_Delivery = 'дю'
WHERE name_store = 'BestMarket';