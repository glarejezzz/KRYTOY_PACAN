USE fabric;
GO

DROP FUNCTION IF EXISTS dbo.TotalEntranceCostByProduct;
GO

CREATE FUNCTION dbo.TotalEntranceCostByProduct(@product_name VARCHAR(64))
RETURNS MONEY
AS
BEGIN
    DECLARE @total_cost MONEY;
    SELECT @total_cost = SUM(m.price * e.amount)
    FROM model m
    INNER JOIN entrance e ON m.model_name = e.model_name
    WHERE m.product_name = @product_name;
    RETURN ISNULL(@total_cost, 0);
END;
GO

SELECT dbo.TotalEntranceCostByProduct('Блузка') AS Стоимость_всех;