CREATE VIEW wv_price_elasticity_study AS
SELECT 
    product_name AS 'товар',
    price AS 'текущая цена',
    sales_monthly AS 'продажи летом',
    sales_monthly * seasonal_factor AS 'продажи зимой',
    optimal_price AS 'оптимальная цена',
    CASE 
        WHEN MONTH(GETDATE()) IN (6,7,8) THEN price * sales_monthly
        ELSE price * (sales_monthly * seasonal_factor)
    END AS 'сезонная выручка'
FROM product;
GO