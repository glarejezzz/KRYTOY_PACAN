use online_sale

go

SELECT 
os.name_store AS 'Название магазина',
os.email AS 'Почта магазина',
os.paymant_for_Delivery AS 'Оплата доставки', 
os.quantity_product AS 'Количество товаров'
FROM online_store os

SELECT 
p.id_product AS 'ID продукта',
p.product_name AS 'Название товара',
p.firm AS 'Фирма',
p.model AS 'Модель',
p.technical_specifications AS 'Технические характеристики',
p.price AS 'Цена',
p.Warranty_period AS 'Гарантийный срок',
p.quantity AS 'В наличии',
p.number_of_view AS 'Количество просмотров',
p.adding_cart AS 'Добавленных в корзину',
p.completed_order AS 'Оформленных заказов'
FROM product p;

SELECT 
c.id_client AS 'ID клиента',
c.name_client AS 'ФИО клиента', 
c.address_client AS 'Адрес клиента', 
c.phone_number AS 'Номер клиента'
FROM client c

SELECT 
c.id_client AS 'ID клиента',
d.order_number AS 'Номер заказа', 
os.name_store AS 'Название  магазина', 
po.number_of_products AS 'Количество товара', 
po.order_date AS 'Дата заказа' , 
po.order_status AS 'Статус заказа'
FROM product_order po
LEFT JOIN delivery d ON po.order_number = d.order_number
INNER JOIN client c ON po.id_client = c.id_client
INNER JOIN online_store os ON po.name_store = os.name_store


SELECT 

d.order_number AS 'Номер заказа',
d.delivery_date AS 'Дата доставки',
d.delivery_time AS 'Время доставки' ,
d.delivery_address AS 'Адрес доставки',
d.name_courier AS 'ФИО курьера'
FROM delivery d;



