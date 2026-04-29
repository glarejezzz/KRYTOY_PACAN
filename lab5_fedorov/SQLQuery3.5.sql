CREATE VIEW wv_warranty_claim_analysis AS
SELECT 
    product_name AS 'название продукта',
    firm AS 'фирма',
    price AS 'цена',
    Warranty_period AS '√арантийный период',
    quantity AS ' количество',
    sales_monthly AS 'объем продаж в мес€ц',
    warranty_claims AS 'гарантийные требовани€',
    avg_time_to_failure_months AS 'среднее врем€ от врем€ до отказа в мес€це',
    reliability_rating AS 'оценка надежности'
FROM product;
GO