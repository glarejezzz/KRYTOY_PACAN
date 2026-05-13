USE fabric;
GO

CREATE TRIGGER tr_product_block_delete
ON product
INSTEAD OF DELETE
AS
BEGIN
    SET NOCOUNT ON;
    
    IF EXISTS (
        SELECT 1 
        FROM deleted d
        INNER JOIN model m ON m.product_name = d.product_name
    )
    BEGIN
        RAISERROR('Нельзя удалить товар, пока существуют его модели!', 16, 1);
        RETURN;
    END
    
    DELETE FROM product 
    WHERE product_name IN (SELECT product_name FROM deleted);
END;
GO

SELECT * FROM product;
DELETE FROM product WHERE product_name = 'Бриджи';

INSERT INTO product (product_name, product_type) VALUES
('Бриджи','Нижняя одежка');