using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class NewBehaviourScript : MonoBehaviour
{
    public Text prueba;
    public GameObject dbs;

    // Start is called before the first frame update
    void Start()
    {
        //dbs = GameObject.Find("DB");
        if (dbs == null)
            return;
        prueba = gameObject.GetComponent<Text>();

        prueba.text = dbs.GetComponent<main>().GetItems();
        Debug.Log(prueba.text);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
