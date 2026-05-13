USE fabric;
GO

DROP FUNCTION IF EXISTS dbo.ModelsByCategoryAndSize;
GO

CREATE FUNCTION dbo.ModelsByCategoryAndSize(@product_type VARCHAR(32), @size_category VARCHAR(20))
RETURNS TABLE
AS
RETURN (
    SELECT 
        m.model_name, 
        m.price, 
        m.material, 
        m.color,
        CASE 
            WHEN m.price < 5000 THEN 'XS/S'
            WHEN m.price < 15000 THEN 'M/L' 
            ELSE 'XL/XXL'
        END AS size
    FROM model m
    JOIN product p ON m.product_name = p.product_name
    WHERE p.product_type = @product_type 
      AND (
          (@size_category = 'Малый' AND m.price < 5000) OR
          (@size_category = 'Средний' AND m.price < 15000) OR
          (@size_category = 'Большой' AND m.price >= 15000)
      )
);
GO

SELECT * FROM dbo.ModelsByCategoryAndSize('Мужская одежда', 'Средний');
GO

SELECT * FROM product;