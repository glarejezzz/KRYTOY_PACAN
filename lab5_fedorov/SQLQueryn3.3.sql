use online_sale
go

CREATE VIEW wv_store_performance_dashboard AS
SELECT 
    s.name_store AS 'Название магазина',
    COUNT(p.order_number) AS 'Номер заказа',
    SUM(1) AS 'всего',
    100 - (SUM(CASE WHEN p.order_status = 'ОТМЕНЕН' THEN 100 ELSE 0 END) / COUNT(p.order_number)) AS 'Конверсия'
FROM online_store s
LEFT JOIN product_order p ON s.name_store = p.name_store
GROUP BY s.name_store;
GO