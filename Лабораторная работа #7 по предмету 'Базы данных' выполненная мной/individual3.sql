USE fabric;
GO

DROP FUNCTION IF EXISTS dbo.GetSeasonality;
GO

CREATE FUNCTION dbo.GetSeasonality(@model_name VARCHAR(64))
RETURNS VARCHAR(10)
AS
BEGIN
    DECLARE @season VARCHAR(10);
    
    SELECT @season = CASE
        WHEN material IN ('Пуховик', 'Кашемир', 'Шерсть') 
             OR color IN ('Черный', 'Серый', 'Темно-синий') THEN 'Зима'
        WHEN material IN ('Хлопок', 'Деним') 
             AND color IN ('Белый', 'Голубой', 'Синий', 'Хаки') THEN 'Лето'
        ELSE 'Всесезон'
    END
    FROM model 
    WHERE model_name = @model_name;
    
    RETURN ISNULL(@season, 'Демисезон');
END;
GO

SELECT model_name, dbo.GetSeasonality(model_name) AS seasonality 
FROM model;
GO