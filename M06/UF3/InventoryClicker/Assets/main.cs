using UnityEngine;

using System.Collections;
using System.Collections.Generic;

using System.Data;
using Mono.Data.Sqlite;
using System.IO;
using System;

public class main : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        //IDbConnection dbcon = new SqliteConnection(connection);
        //dbcon.Open();

        //IDbCommand dbcmd; //Envia comandos a la base de datos
        //IDataReader reader1;

        //CREATE TABLE IF NOT EXIST "items"(
        //    "id_item"   INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        //    "item"  TEXT NOT NULL,
        //    "price" INTEGER NOT NULL,
        //    "img"   TEXT,
        //    "desc"  TEXT
        //);
        //CREATE TABLE IF NOT EXIST "players"(
        //    "id_player" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        //    "name"  TEXT NOT NULL,
        //    "user"  TEXT NOT NULL,
        //    "password"  TEXT NOT NULL,
        //    "money" INTEGER NOT NULL DEFAULT 0,
        //    "img"   TEXT
        //);
        //CREATE TABLE IF NOT EXIST "inventory"(
        //    "id_inventory"  INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        //    "id_player" INTEGER NOT NULL,
        //    "id_item"   INTEGER NOT NULL,
        //);
        //string q_createTable =
        //  "CREATE TABLE IF NOT EXISTS my_table (id INTEGER PRIMARY KEY, val INTEGER )";

        //dbcmd = dbcon.CreateCommand();
        //dbcmd.CommandText = q_createTable;
        //reader1 = dbcmd.ExecuteReader();

        //IDbCommand cmnd = dbcon.CreateCommand();
        //cmnd.CommandText = "INSERT INTO my_table (id, val) VALUES (0, 5)";
        //cmnd.ExecuteNonQuery();

        //IDbCommand cmnd_read = dbcon.CreateCommand();
        //IDataReader reader;
        //string query = "SELECT * FROM my_table";
        //cmnd_read.CommandText = query;
        //reader = cmnd_read.ExecuteReader();
        //while (reader.Read())
        //{
        //    Debug.Log("id: " + reader[0].ToString());
        //    Debug.Log("val: " + reader[1].ToString());
        //}
        //dbcon.Close();
    }

    public string GetMoney(int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "SELECT money FROM players WHERE id_player=" + user;
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        string res = reader[0].ToString();
        dbcon.Close();
        return res;   
    }

    public string GetItems()
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmndCount = dbcon.CreateCommand();
        IDataReader readerCount;
        string queryCount = "SELECT COUNT(id_item) FROM items";
        cmndCount.CommandText = queryCount;
        readerCount = cmndCount.ExecuteReader();

        readerCount.Read();
        int numItems;
        int.TryParse(readerCount[0].ToString(), out numItems);

        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "SELECT item, price, desc FROM items";
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        int i = 0;
        string[] res = new string[numItems];
        string result = "";
        while (reader.Read())
        { 
            res = new string[] { reader[i].ToString() };
            result += reader[i].ToString();
            result += reader[i+1].ToString();
            result += reader[i+2].ToString();
            i++;
        }
            
        dbcon.Close();
        return result;
    }

    public void UpdateMoney(int money, int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "UPDATE players SET money=" + money + " WHERE id_player =" + user;
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        dbcon.Close();
    }

    public void BuyItem(int item, int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "INSERT INTO inventory (id_item, id_player) VALUES (" + item + "," + user + ")";
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        dbcon.Close();
    }
    
    public string GetQuantity(int item, int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "SELECT COUNT(" + item + ") FROM inventory WHERE id_player=" + user;
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        string res = reader[0].ToString();
        dbcon.Close();
        return res;
    }

    public string GetPlayerItems(int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "SELECT item, price, img, desc FROM items WHERE players.id_player=" + user;
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        string res = reader[0].ToString();
        dbcon.Close();
        return res;
    }

    public string GetPlayer(int user)
    {
        string connection = "URI=file:" + Application.persistentDataPath + "/My_Database";

        IDbConnection dbcon = new SqliteConnection(connection);
        dbcon.Open();
        IDbCommand cmnd = dbcon.CreateCommand();
        IDataReader reader;
        string query = "SELECT name, money, img FROM players WHERE id_player=" + user;
        cmnd.CommandText = query;
        reader = cmnd.ExecuteReader();

        reader.Read();
        string res = reader[0].ToString();
        dbcon.Close();
        return res;
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
