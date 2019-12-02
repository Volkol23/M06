using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Store : MonoBehaviour
{
    public GameObject itemPrefab;

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            GameObject item = Instantiate(itemPrefab);
            item.transform.SetParent(transform, false);

            Text textName = item.GetComponent<Text>();
            textName.text = "Cuchillo";
        }

    } 
  
}
