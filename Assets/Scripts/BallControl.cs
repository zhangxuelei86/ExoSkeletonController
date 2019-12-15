using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallControl : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //Randomize Ball's speed
        float speedX = Random.Range(5, 7);
        float speedY = Random.Range(2, 5);
        GetComponent<Rigidbody>().velocity = new Vector3(speedX, speedY, 0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
