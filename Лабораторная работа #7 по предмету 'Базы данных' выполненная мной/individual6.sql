USE fabric;
GO
DROP FUNCTION IF EXISTS dbo.AvgMaterialUnitCost;
GO

CREATE FUNCTION dbo.AvgMaterialUnitCost(@material VARCHAR(32))
RETURNS MONEY
AS
BEGIN
    DECLARE @avg_cost MONEY;
    
    SELECT @avg_cost = AVG(unit_cost)
    FROM material_costs 
    WHERE material = @material;
    
    RETURN ISNULL(@avg_cost, 0);
END;
GO

SELECT 
    material,
    dbo.AvgMaterialUnitCost(material) AS avg_unit_cost
FROM (SELECT DISTINCT material FROM material_costs) materials;
GO