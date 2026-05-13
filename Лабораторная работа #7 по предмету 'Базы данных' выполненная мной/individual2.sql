USE fabric;
GO

DROP FUNCTION IF EXISTS dbo.EntranceHistoryByModel;
GO

CREATE FUNCTION dbo.EntranceHistoryByModel(@model_name VARCHAR(64))
RETURNS TABLE
AS
RETURN (
    SELECT id, entrance_date, amount, responsible
    FROM entrance
    WHERE model_name = @model_name
);
GO

SELECT * FROM dbo.EntranceHistoryByModel('Ïאכüעמ_Øונסעü');