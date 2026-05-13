USE fabric;
GO

CREATE TRIGGER tr_entrance_update_stock
ON entrance
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;
    
    UPDATE i
    SET avg_stock = i.avg_stock + ie.amount
    FROM inventory i
    INNER JOIN inserted ie ON i.product_name = (
        SELECT product_name 
        FROM model m 
        WHERE m.model_name = ie.model_name
    )
    WHERE EXISTS (
        SELECT 1 
        FROM model m 
        WHERE m.model_name = ie.model_name 
        AND m.product_name = i.product_name
    );
   
END;
GO

SELECT * FROM inventory WHERE product_name = 'Куртка';
INSERT INTO entrance (model_name, entrance_date, amount, responsible) VALUES ('Куртка_Зима','15.01.2025 10:00',10,'Иванов');
SELECT * FROM inventory WHERE product_name = 'Куртка';