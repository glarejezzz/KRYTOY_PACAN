use online_sale
go

CREATE VIEW wv_product_cross_selling_potential AS
SELECT 
    p1.product_name AS товар,
    p2.product_name AS 'рекомендуемый товар',
    COUNT(*) AS 'частота совместных покупок',
    COUNT(*) * AVG(b.price) AS 'потенциал выручки'
FROM order_item a
JOIN order_item b ON a.order_number = b.order_number
JOIN product p1 ON a.product_id = p1.id_product
JOIN product p2 ON b.product_id = p2.id_product
WHERE a.product_id < b.product_id
GROUP BY p1.product_name, p2.product_name;