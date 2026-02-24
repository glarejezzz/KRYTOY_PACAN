use online_sale

go

SELECT 
name_store AS 'Название магазина',
email AS 'Почта магазина',
paymant_for_Delivery AS 'Оплата доставки', 
quantity_product AS 'Количество товаров'
FROM online_store;

SELECT 
id_product AS 'ID продукта',
product_name AS 'Название товара',
firm AS 'Фирма',
model AS 'Модель',
technical_specifications AS 'Технические характеристики',
price AS 'Цена',
Warranty_period AS 'Гарантийный срок',
quantity AS 'в наличии',
number_of_view AS 'Количество просмотров',
adding_cart AS 'Добавленных в корзину'
FROM product;

SELECT 
id_client AS 'ID клиента',
name_client AS 'ФИО клиента', 
address_client AS 'Адрес клиента', 
phone_number AS 'Номер клиента'
FROM client;

SELECT 
id_client AS 'ID клиента',
order_number AS 'Номер заказа', 
name_store AS 'Название  магазина', 
number_of_products AS 'Количество товара', 
order_date AS 'Дата заказа' , 
order_status AS 'Статус заказа',
completed_order AS 'Оформленных заказов'
FROM product_order;

SELECT 

order_number AS 'Номер заказа',
delivery_date AS 'Дата доставки',
delivery_time AS 'Время доставки' ,
delivery_address AS 'Адрес доставки',
name_courier AS 'ФИО курьера'
FROM delivery;

