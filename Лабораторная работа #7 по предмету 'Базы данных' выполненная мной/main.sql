USE fabric;
GO

CREATE FUNCTION dbo.GetMaxOfThree(@a DECIMAL(10,2), @b DECIMAL(10,2), @c DECIMAL(10,2))
RETURNS DECIMAL(10,2)
AS
BEGIN
    DECLARE @max DECIMAL(10,2);
    SET @max = @a;
    IF @b > @max SET @max = @b;
    IF @c > @max SET @max = @c;
    RETURN @max;
END;
GO

SELECT 
    model_name,
    dbo.GetMaxOfThree(price, cost_price, defect_rate) AS Макс_фин_показатель
FROM model;
GO