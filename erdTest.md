```mermaid
erDiagram
    SETTINGS {
        int         setting_id      PK
        varchar     setting_key     "UNIQUE, NOT NULL"
        nvarchar    value           "NOT NULL"
    }

    USERS {
        int         user_id         PK
        varchar     username        "UNIQUE, NOT NULL"
        varchar     email           "UNIQUE, NOT NULL"
        varchar     password_hash   "NOT NULL"
        nvarchar    full_name
        varchar     phone
        nvarchar    address
        varchar     role            "DEFAULT 'Customer'"
        bit         is_active       "DEFAULT 1"
        datetime2   created_at      "DEFAULT GETDATE()"
        datetime2   updated_at      "DEFAULT GETDATE()"
    }

    CATEGORIES {
        int         category_id     PK
        nvarchar    category_name   "NOT NULL"
    }

    PRODUCTS {
        int         product_id      PK
        nvarchar    product_name    "NOT NULL"
        decimal     price           "NOT NULL"
        int         category_id     FK
        nvarchar    image_url
        nvarchar    description
        datetime2   created_at      "DEFAULT GETDATE()"
    }

    ORDERS {
        int         order_id        PK
        int         user_id         FK
        datetime2   order_date      "DEFAULT GETDATE()"
        decimal     total_amount    "NOT NULL"
        varchar     status          "DEFAULT 'Pending'"
    }

    ORDERDETAILS {
        int         order_detail_id PK
        int         order_id        FK
        int         product_id      FK
        int         quantity        "NOT NULL"
        decimal     price           "NOT NULL"
    }

    %% RELATIONSHIPS
    USERS       ||--o{ ORDERS        : "user_id"
    CATEGORIES  ||--o{ PRODUCTS      : "category_id"
    ORDERS      ||--o{ ORDERDETAILS  : "order_id"
    PRODUCTS    ||--o{ ORDERDETAILS  : "product_id"
