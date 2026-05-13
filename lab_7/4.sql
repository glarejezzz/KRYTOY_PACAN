
USE Tour
GO

ALTER TABLE sale ADD VisaRequired NVARCHAR(20) DEFAULT NULL;
GO

CREATE TRIGGER trg_sale_visa
ON sale
AFTER INSERT
AS
BEGIN
    UPDATE s
    SET VisaRequired = IIF(c.cost_visa = 0, 'Нет', 'Да')
    FROM sale s
    INNER JOIN inserted i ON s.id_sale = i.id_sale
    INNER JOIN marshrut m ON i.id_route = m.id_route
    INNER JOIN country c ON m.id_country = c.id_country;
END
GO

INSERT INTO sale (id_client, id_route, number_contract, full_name_client, name_route, destination_country, ticket_price, quantity_ticket, date_sale, sales_manager) 
VALUES (1, 4, 'TEST-VISA-001', 'Кузнецов Сергей', 'Россия', 'Москва', 2000, 5, GETDATE(), 'Менеджер'),
(2, 6, 'TEST-VISA-003', 'Кузнецов Сергей', 'Дубай', 'ОАЭ', 1500, 1, GETDATE(), 'Менеджер');


SELECT id_client, id_route, name_route, destination_country, VisaRequired 
FROM sale 
WHERE number_contract = 'TEST-VISA-003';

SELECT id_client, id_route, name_route, destination_country, VisaRequired 
FROM sale 
WHERE number_contract = 'TEST-VISA-001';


--    ▄▄▄▄▄   █  █▀ ▄█ ▄█ ▄███▄     ▄▄▄▄▄   ▄███▄   ██  
--   █     ▀▄ █▄█   ██ ██ █▀   ▀   █     ▀▄ █▀   ▀  █ █ 
-- ▄  ▀▀▀▀▄   █▀▄   ██ ██ ██▄▄   ▄  ▀▀▀▀▄   ██▄▄    █▄▄█
--  ▀▄▄▄▄▀    █  █  ▐█ ▐█ █▄   ▄▀ ▀▄▄▄▄▀    █▄   ▄▀ █  █
--              █    ▐  ▐ ▀███▀             ▀███▀      █
--             ▀                                      █ 
--            