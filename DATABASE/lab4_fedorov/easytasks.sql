USE online_sales

GO
--1.
select *
FROM product
WHERE product_name = 'Утюг'
--2.
SELECT *
FROM product_order
where order_date >='2024-01-01'
--3.
SELECT * 
FROM online_store
ORDER BY name_store;




