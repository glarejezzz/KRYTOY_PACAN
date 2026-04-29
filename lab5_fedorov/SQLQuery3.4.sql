CREATE VIEW Wv_delivery_efficiency_metrics AS
SELECT 
    order_number as 'номер заказа' ,
    delivery_date as 'дата доставки',   
    delivery_address as 'адрес доставки',     
    name_courier as 'имена курьера',         
    distance_km as 'дистанция км',          
    logistics_cost as 'логистическая  стоимость',        
    customer_satisfaction 'Удовлетворенность клиента'
FROM delivery;
GO
