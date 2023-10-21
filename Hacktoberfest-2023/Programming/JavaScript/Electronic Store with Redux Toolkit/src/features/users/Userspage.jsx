import React,{useEffect} from 'react'

import {useDispatch,useSelector} from 'react-redux'
import { fetchusers } from './usersSlice'

function Userspage() {

    const dispatch = useDispatch()

    const users = useSelector((state)=>state.users)

    useEffect(()=>{
        dispatch(fetchusers())

    }, [])


  return (
    <div>
        
        <h1>Users Page</h1>

        {users.loading ? <div> Loading... </div>:null}
        {!users.loading && users.error ? <h1>{users.error}</h1>:null}
        {
            !users.loading && users.users.length ? 

            (
                <ul>
                    {users.users.map((user)=>
                        <li key={user.id}>{user.name}</li>
                    
                    )}


                </ul>
            ):null

        }

    </div>
  )
}

export default Userspage