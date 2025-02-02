PGDMP      %                |            account    16.3    16.3     �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            �           1262    16396    account    DATABASE     �   CREATE DATABASE account WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'English_United Kingdom.1258';
    DROP DATABASE account;
                postgres    false            �            1259    32777 	   customers    TABLE     �   CREATE TABLE customer_order.customers (
    id integer NOT NULL,
    first_name character varying(255) NOT NULL,
    last_name character varying(255) NOT NULL,
    email character varying(255) NOT NULL,
    balance double precision NOT NULL
);
 %   DROP TABLE customer_order.customers;
       customer_order         heap    postgres    false            �            1259    32776    customers_id_seq    SEQUENCE     �   CREATE SEQUENCE customer_order.customers_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 /   DROP SEQUENCE customer_order.customers_id_seq;
       customer_order          postgres    false    219            �           0    0    customers_id_seq    SEQUENCE OWNED BY     U   ALTER SEQUENCE customer_order.customers_id_seq OWNED BY customer_order.customers.id;
          customer_order          postgres    false    218            �            1259    32814    orders    TABLE     �   CREATE TABLE customer_order.orders (
    id integer NOT NULL,
    description character varying(1000) NOT NULL,
    price double precision NOT NULL,
    created_date timestamp without time zone DEFAULT now() NOT NULL,
    customer_id integer NOT NULL
);
 "   DROP TABLE customer_order.orders;
       customer_order         heap    postgres    false            �            1259    32813    orders_id_seq    SEQUENCE     �   CREATE SEQUENCE customer_order.orders_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 ,   DROP SEQUENCE customer_order.orders_id_seq;
       customer_order          postgres    false    221                        0    0    orders_id_seq    SEQUENCE OWNED BY     O   ALTER SEQUENCE customer_order.orders_id_seq OWNED BY customer_order.orders.id;
          customer_order          postgres    false    220            ^           2604    32780    customers id    DEFAULT     |   ALTER TABLE ONLY customer_order.customers ALTER COLUMN id SET DEFAULT nextval('customer_order.customers_id_seq'::regclass);
 C   ALTER TABLE customer_order.customers ALTER COLUMN id DROP DEFAULT;
       customer_order          postgres    false    218    219    219            _           2604    32817 	   orders id    DEFAULT     v   ALTER TABLE ONLY customer_order.orders ALTER COLUMN id SET DEFAULT nextval('customer_order.orders_id_seq'::regclass);
 @   ALTER TABLE customer_order.orders ALTER COLUMN id DROP DEFAULT;
       customer_order          postgres    false    221    220    221            �          0    32777 	   customers 
   TABLE DATA           V   COPY customer_order.customers (id, first_name, last_name, email, balance) FROM stdin;
    customer_order          postgres    false    219   �       �          0    32814    orders 
   TABLE DATA           [   COPY customer_order.orders (id, description, price, created_date, customer_id) FROM stdin;
    customer_order          postgres    false    221   o                  0    0    customers_id_seq    SEQUENCE SET     G   SELECT pg_catalog.setval('customer_order.customers_id_seq', 1, false);
          customer_order          postgres    false    218                       0    0    orders_id_seq    SEQUENCE SET     D   SELECT pg_catalog.setval('customer_order.orders_id_seq', 1, false);
          customer_order          postgres    false    220            b           2606    32782    customers customers_pkey 
   CONSTRAINT     ^   ALTER TABLE ONLY customer_order.customers
    ADD CONSTRAINT customers_pkey PRIMARY KEY (id);
 J   ALTER TABLE ONLY customer_order.customers DROP CONSTRAINT customers_pkey;
       customer_order            postgres    false    219            d           2606    32822    orders orders_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY customer_order.orders
    ADD CONSTRAINT orders_pkey PRIMARY KEY (id);
 D   ALTER TABLE ONLY customer_order.orders DROP CONSTRAINT orders_pkey;
       customer_order            postgres    false    221            e           2606    32823    orders orders_customer_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY customer_order.orders
    ADD CONSTRAINT orders_customer_id_fkey FOREIGN KEY (customer_id) REFERENCES customer_order.customers(id) ON UPDATE RESTRICT ON DELETE CASCADE;
 P   ALTER TABLE ONLY customer_order.orders DROP CONSTRAINT orders_customer_id_fkey;
       customer_order          postgres    false    221    4706    219            �   �   x�m�1�0����iBw�"n'���&�K�V�o�Jo8���38p�%#���q��,���V�!�,�A�K��6l�V���tu9��e������2N,�j�6� �A?��p_2MK^��ѕ{jcr/r�!ڕ3��V]I)�tDIX      �   �   x�mλ�0 й���������c�8�)�H����$$���Aq�j77Pv�?���5�����7�^c{��:֙ Ei��5�� ���Hێo<��֑����xz������%wq����G�{��C'heP*�KH��5�R~ ��=`     