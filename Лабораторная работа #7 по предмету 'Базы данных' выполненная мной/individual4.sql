USE fabric;
GO
DROP FUNCTION IF EXISTS dbo.WarehouseReport;
GO

CREATE FUNCTION dbo.WarehouseReport()
RETURNS TABLE
AS
RETURN (
    WITH StockCalc AS (
        SELECT 
            e.model_name,
            SUM(e.amount) AS total_entered,
            SUM(p.total_produced) AS total_produced,
            SUM(s.quantity) AS total_sold,
            SUM(p.total_produced) - SUM(s.quantity) AS current_stock
        FROM model m
        LEFT JOIN entrance e ON m.model_name = e.model_name
        LEFT JOIN production p ON m.model_name = p.model_name
        LEFT JOIN sales s ON m.model_name = s.model_name
        GROUP BY e.model_name
    )
    SELECT 
        sc.model_name,
        ISNULL(sc.total_entered, 0) AS total_entered,
        ISNULL(sc.current_stock, 0) AS current_stock,
        CASE 
            WHEN ISNULL(sc.current_stock, 0) < 50 THEN 'Требует пополнения'
            ELSE 'Норма'
        END AS replenishment_flag
    FROM StockCalc sc
);
GO

SELECT * FROM dbo.WarehouseReport();
GO