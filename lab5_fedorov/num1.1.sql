use online_sale
go

CREATE VIEW vw_customer_purchase_funnel
AS SELECT p.number_of_view AS 'Количество просмотров',
p.adding_cart AS 'Добавленных в корзину',
p.completed_order AS 'Оформленных заказов'
from product p