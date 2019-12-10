using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class NewBehaviourScript : MonoBehaviour
{
    public Text prueba;
    public Text prueba1;
    public Text prueba2;
    public GameObject dbs;

    // Start is called before the first frame update
    void Start()
    {
        if (dbs == null)
            return;
        prueba = gameObject.GetComponent<Text>();
        prueba1 = gameObject.GetComponent<Text>();
        prueba2 = gameObject.GetComponent<Text>();

        string res = dbs.GetComponent<main>().GetItems();
        char separator = ';';

        string[] items = res.Split(separator);
        Debug.Log(items[0]);
        for(int i = 0; i < 9;i += 3)
        {
            prueba.text = items[i];
            prueba1.text = items[i+1];
            prueba2.text = items[i+2];
        }
        Debug.Log(prueba.text);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
