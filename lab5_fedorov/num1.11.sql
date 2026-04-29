USE online_sale

go

CREATE VIEW vw_customer_purchase_funnel

AS 
SELECT number_views,additions_cart, completed_orders, conf_del_order;
from product